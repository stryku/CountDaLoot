from subprocess import call
call(["cloc.exe", ".", "--exclude-dir=tmp,resources,releases,cmake,build,bin,3rdparty"])