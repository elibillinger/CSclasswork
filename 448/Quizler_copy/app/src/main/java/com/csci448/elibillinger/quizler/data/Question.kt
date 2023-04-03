package com.csci448.elibillinger.quizler.data

import java.lang.Boolean.FALSE

class Question(question: Int, answer: Boolean) {
    val textReadId : Int = question;
    val isAnswerTrue : Boolean = answer;
}