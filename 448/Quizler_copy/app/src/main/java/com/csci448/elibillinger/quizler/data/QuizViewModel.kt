package com.csci448.elibillinger.quizler.data

import android.util.Log
import androidx.lifecycle.ViewModel
import com.csci448.elibillinger.quizler.R

class QuizViewModel(private var currentQuestionIndex: Int , private var currentGameScore: Int ) : ViewModel() {
    private val questionBank: MutableList<Question> = mutableListOf()
    private var cheated : Boolean = false
    val didUserCheat : Boolean
        get() = cheated
    val currentIndex : Int
        get() = currentQuestionIndex

    val score : Int
        get() = currentGameScore

    companion object {
        private const val LOG_TAG = "448.QuizViewModel"
    }

    init {
        Log.d(LOG_TAG, "ViewModel instance created")
        questionBank.add(Question(R.string.question_1, false))
        questionBank.add(Question(R.string.question_2, true))
        questionBank.add(Question(R.string.question_3, true))
        questionBank.add(Question(R.string.question_4, false))
    }

    override fun onCleared() {
        super.onCleared()
        Log.d(LOG_TAG, "ViewModel instance about to be destroyed")
    }

    private val currentQuestion: Question
        get() = questionBank[currentQuestionIndex]

    val currentQuestionTextId: Int
        get() = currentQuestion.textReadId

    val currentQuestionAnswer: Boolean
        get() = currentQuestion.isAnswerTrue

    val currentScore: Int
        get() = score

    fun userCheated(){
        cheated = true
    }

    fun moveToNextQuestion() {
        if(currentQuestionIndex < questionBank.size - 1){
            currentQuestionIndex++
        } else {
            currentQuestionIndex = 0
        }
        cheated = false
    }

    fun moveToPreviousQuestion() {
        if(currentQuestionIndex > 0){
            currentQuestionIndex--
        } else {
            currentQuestionIndex = questionBank.size - 1
        }
        cheated = false
    }

    fun isAnswerCorrect(guess : Boolean): Boolean {
        return if (guess == currentQuestionAnswer && !didUserCheat) {
            currentGameScore++
            true
        } else {
            false
        }
    }
}

