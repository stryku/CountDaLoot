from subprocess import Popen, PIPE

def get_total_loc(output_lines):
    for line in output_lines:
        if line.startswith('SUM'):
            clear_str = " ".join(line.split())
            lines_counts = [int(x) for (x) in clear_str.split(' ')[-3:]]
            return sum(lines_counts)
            
    return 0


proc = Popen(["cloc", ".", "--exclude-dir=tmp,resources,releases,cmake,build,bin,3rdparty,data"], stdout=PIPE)
loc = get_total_loc(proc.stdout.read().splitlines())
print(loc)
