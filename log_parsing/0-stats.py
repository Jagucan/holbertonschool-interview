#!/usr/bin/python3
""" Modules that reads stdin line by line and       
    computes metrics.

"""
import sys


def print_metrics(file_size, status_codes):
    """ def print metrics for a given file size
        and status codes

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
