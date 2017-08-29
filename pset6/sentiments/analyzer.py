import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.good, self.bad = set(), set()

        # Open file for each file
        goodfile = open(positives, "r")
        badfile = open(negatives, "r")

        # Init the sets
        for line in goodfile:
            if line[0] != ';' and line[0] != '\n':
                self.good.add(line.rstrip("\n"))

        for line in badfile:
            if line[0] != ';' and line[0] != '\n':
                self.bad.add(line.rstrip("\n"))

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # Calculate score
        if text.lower() in self.good:
            score = 1
        elif text.lower() in self.bad:
            score = -1
        else:
            score = 0

        return score