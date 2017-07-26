from subprocess import Popen, PIPE


def get_total_loc(output_lines):
    for line in output_lines:
        str_line = line.decode("utf-8")
        if str_line.startswith('SUM'):
            clear_str = " ".join(str_line.split())
            lines_counts = [int(x) for (x) in clear_str.split(' ')[-3:]]
            return sum(lines_counts)
            
    return 0


def get_loc():
    proc = Popen(["cloc", ".", "--exclude-dir=tmp,resources,releases,cmake,build,bin,3rdparty,data,.idea,utils/scripts/build/build,utils/scripts/__pycache__"], stdout=PIPE, cwd='../..')
    return get_total_loc(proc.stdout.read().splitlines())
    

if __name__ == "__main__":
    print(get_loc())
