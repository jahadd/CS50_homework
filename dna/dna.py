import csv
import sys


def main():
    # ✅ Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # ✅ Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        database = list(reader)
        str_list = reader.fieldnames[1:]  # Excluye la columna 'name'

    # ✅ Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        dna_sequence = file.read()

    # ✅ Find longest match of each STR in DNA sequence
    str_counts = {}
    for STR in str_list:
        str_counts[STR] = longest_match(dna_sequence, STR)

    # ✅ Check database for matching profiles
    for person in database:
        match = True
        for STR in str_list:
            if int(person[STR]) != str_counts[STR]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run


main()
