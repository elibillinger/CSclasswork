package com.csci448.elibillinger_A2.quizler.data

import android.util.Log
import androidx.lifecycle.ViewModel
import com.csci448.elibillinger_A2.quizler.R


class QuizViewModel(private var currentQuestionIndex: Int , private var currentGameScore: Int ) : ViewModel() {
    private val questionBank: MutableList<Question> = mutableListOf()
    val answeredQuestions = ArrayList<Int>()
    val cheatQuestions = ArrayList<Int>()
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
        questionBank.add(TFQuestion(R.string.question_1,QuestionType.TF, false))
        questionBank.add(TFQuestion(R.string.question_2,QuestionType.TF, true))
        questionBank.add(TFQuestion(R.string.question_3,QuestionType.TF, true))
        questionBank.add(TFQuestion(R.string.question_4,QuestionType.TF, false))
        questionBank.add(MultipleChoiceQuestion(R.string.question_5,QuestionType.MULTIPLE, 3,
            R.string.question_5_choice_1,R.string.question_5_choice_2,R.string.question_5_choice_3,R.string.question_5_choice_4))
        questionBank.add(FillQuestion(R.string.question_6,QuestionType.FILL,  "Jupiter"))
    }

    override fun onCleared() {
        super.onCleared()
        Log.d(LOG_TAG, "ViewModel instance about to be destroyed")
    }

    private val currentQuestion: Question
        get() = questionBank[currentQuestionIndex]

    val currentQuestionTextId: Int
        get() = currentQuestion.textReadId

    val currentQuestionType: QuestionType
        get() = currentQuestion.questionType

    val currentQuestionAnswer: String
        get() = currentQuestion.isAnswerTrue

    val currentQuestionChoice1: Int
        get() = currentQuestion.option1

    val currentQuestionChoice2: Int
        get() = currentQuestion.option2

    val currentQuestionChoice3: Int
        get() = currentQuestion.option3

    val currentQuestionChoice4: Int
        get() = currentQuestion.option4

    val hasQuestionBeenAnswered: Boolean
        get() = currentQuestion.questionAnswered

    val currentScore: Int
        get() = score

    fun userCheated(){
        cheatQuestions.add(currentIndex)
        cheated = true
    }

    fun checkCheated(){
        cheatQuestions.forEach {
            if(it == currentIndex){
                userCheated()
            }
        }
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

    fun updateAnsweredQuestions(){
        currentQuestion.questionAnswered = true
        answeredQuestions.add(currentIndex)
    }

    fun isAnswerCorrect(guess : String): Boolean {
        updateAnsweredQuestions()
        checkCheated()
        return if (guess == currentQuestionAnswer && !didUserCheat) {
            currentGameScore++
            true
        } else {
            false
        }
    }
}

