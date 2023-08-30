import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)


    # TODO: Read database file into a variable
    STRs = []
    profiles = []

    with open(sys.argv[1], mode="r") as database:
        reader = csv.DictReader(database)
        # Populate list of Short Tandem Repeats (STRs)
        STRs = reader.fieldnames[1:]
        for row in reader:
            # Add person to profiles
            profiles.append(row)

    # Initialise dictionary for sequence file
    seq_subsequence_count = dict.fromkeys(STRs, 0)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], mode="r") as sequence_file:
        sequence = sequence_file.readline()
        for subsequence in STRs:
            seq_subsequence_count[subsequence] = longest_match(sequence, subsequence)

    # TODO: Check database for matching profiles
    for profile in profiles:
        match_count = 0

        for subsequence in STRs:
            if int(profile[subsequence]) != seq_subsequence_count[subsequence]:
                continue
            match_count += 1

        if match_count == len(STRs):
            print(profile['name'])
            exit(0)

    print("No match")
    exit(1)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
