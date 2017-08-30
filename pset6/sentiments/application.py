from flask import Flask, redirect, render_template, request, url_for

import os
import sys
import helpers
import nltk
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # absolute paths to lists
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")

    # instantiate analyzer
    analyzer = Analyzer(positives, negatives)

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))

    # get screen_name's tweets
    tweets = (helpers.get_user_timeline(screen_name, 100))

    count, positive, negative, neutral = 0, 0, 0, 0

    # Break into strings
    for element in tweets:
        count += 1
        score = 0
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(element)
        for word in tokens:
            score += analyzer.analyze(word)
        if score > 0:
            positive += 1
        elif score < 0:
            negative += 1
        elif score == 0:
            neutral +=1

    positive = (100 * positive) / count
    negative = (100 * negative) / count
    neutral = (100 * neutral) / count

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
