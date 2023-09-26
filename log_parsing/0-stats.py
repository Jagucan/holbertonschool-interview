#!/usr/bin/python3

import sys


def print_metrics(file_size, status_codes):
    """
    Print the calculated metrics.

    Args:
        file_size (list): List of file sizes.
        status_codes (dict): Dictionary of status codes and their counts.
    """
    total_size = sum(file_size)
    print(f"Total file size: {total_size}")

    sorted_status_codes = sorted(status_codes.keys())
    for code in sorted_status_codes:
        count = status_codes[code]
        print(f"{code}: {count}")


def main():
    """
    The main function that processes input lines and calculates metrics.
    """
    line_count = 0
    file_size = []
    status_codes = {}

    try:
        for line in sys.stdin:
            line = line.strip()
            parts = line.split()

            if len(parts) != 10:
                continue

            ip, _, _, date, _, _, request, status, size, *_ = parts

            if request != '"GET' or not status.isdigit():
                continue

            status = int(status)
            file_size.append(int(size))
            status_codes[status] = status_codes.get(status, 0) + 1

            line_count += 1

            if line_count % 10 == 0:
                print_metrics(file_size, status_codes)

    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
