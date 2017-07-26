import subprocess
import os
import stat
import shutil
import cloc
import time
from git import Repo
from pygithub3 import Github

ROOT = "../.."
BUILD_ROOT = 'build'
CURRENT_CHANGELOG = BUILD_ROOT + '/CHANGELOG.txt'
DEV_CHANGELOG = BUILD_ROOT + '/CHANGELOG_dev.txt'


def get_version():
    return open(ROOT + "/VERSION").read()


def get_current_changelog():
    if not os.path.exists(CURRENT_CHANGELOG):
        return ''

    return open(CURRENT_CHANGELOG).read()


def get_dev_changelog():
    if not os.path.exists(DEV_CHANGELOG):
        return ''

    return open(DEV_CHANGELOG).read()


class ChangelogBuilder:
    def __init__(self):
        self.loc = '0'
        self.current_changelog = ''
        self.dev_changelog = ''
        self.version = ''
        self.date = ''

    def with_loc(self, loc):
        self.loc = loc
        return self

    def with_current_changelog(self, current_changelog):
        self.current_changelog = current_changelog
        return self

    def with_dev_changelog(self, dev_changelog):
        self.dev_changelog = dev_changelog
        return self

    def with_version(self, version):
        self.version = version
        return self

    def with_date(self, date):
        self.date = date
        return self

    def build(self):
        ret = 'v' + self.version
        ret += ' - ' + self.date + '\n'
        ret += '-loc: ' + str(self.loc) + '\n'
        ret += self.dev_changelog + '\n\n'
        ret += self.current_changelog
        return ret


class ChangelogCreator:
    def __init__(self):
        pass

    @staticmethod
    def create():
        current_changelog = get_current_changelog()
        dev_changelog = get_dev_changelog()
        version = get_version()
        loc = cloc.get_loc()
        date = time.strftime("%x")

        builder = ChangelogBuilder()

        return builder.with_current_changelog(current_changelog) \
            .with_dev_changelog(dev_changelog) \
            .with_date(date) \
            .with_loc(loc) \
            .with_version(version) \
            .build()


def write_new_changelog(changelog):
    current_changelog_file = open(CURRENT_CHANGELOG, 'w')
    current_changelog_file.write(changelog)
    open(DEV_CHANGELOG, 'w').close()


def on_rm_error(func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    os.chmod(path, stat.S_IWRITE)
    os.unlink(path)


class RepoHolder:
    def __init__(self):
        self.repo = None
        self.git = None

    @staticmethod
    def clone_repo():
        return Repo.clone_from('https://github.com/stryku/CountDaLoot', 'build')

    def get_branch_name(self):
        return 'build-v' + get_version() + '-release'

    def prepare_repo(self):
        if os.path.exists('build'):
            shutil.rmtree('build', onerror=on_rm_error)

        self.repo = self.clone_repo()
        self.git = self.repo.git
        self.git.checkout('dev')
        writer = self.repo.config_writer()
        writer.set_value('user','name', 'stryku-bot')
        writer.set_value('user','email', 'strykubot@gmail.com')
        writer.write()
        self.git.checkout('HEAD', b=self.get_branch_name())

    def push_release_branch(self):
        self.git.add('--all')
        self.git.commit(m='created ' + get_version() + ' release')
        self.git.tag('v' + get_version())
        TYPE PASSWORD (: subprocess.Popen("git push https://stryku-bot:@github.com/stryku/CountDaLoot --all".split(), cwd='build', stdout=subprocess.PIPE).communicate()


def build_binary():
    if not os.path.exists('build/build'):
        os.makedirs('build/build')

    subprocess.Popen(["cmake", "..", "-DWITH_CONSOLE=OFF", "-DUSE_CLIPBOARD=OFF"], cwd='build/build').communicate()
    subprocess.Popen(["cmake", "--build", ".", "--config", "Release", "--target", "INSTALL"], cwd='build/build').communicate()


def create_zip():
    shutil.make_archive('CountDaLoot-v' + get_version(), 'zip', 'build/bin')


def main():
    print('preparing repo...')
    repo_holder = RepoHolder()
    repo_holder.prepare_repo()

    print('building...')
    build_binary()
    print('creating zip...')
    create_zip()
    changelog_creator = ChangelogCreator()
    write_new_changelog(changelog_creator.create())
    repo_holder.push_release_branch()


if __name__ == "__main__":
    main()
