package com.csci448.elibillinger_A2.quizler.data

enum class QuestionType{
    TF,MULTIPLE,FILL
}

open class Question(question: Int,type: QuestionType) {
    val textReadId : Int = question
    val questionType : QuestionType = type
    open val isAnswerTrue : String = ""
    open val option1 : Int = 0
    open val option2 : Int = 0
    open val option3 : Int = 0
    open val option4 : Int = 0
    var questionAnswered : Boolean = false
}

class TFQuestion(question: Int,type: QuestionType,answer: Boolean): Question(question,type){
    override val isAnswerTrue : String = answer.toString()
}

class FillQuestion(question: Int,type: QuestionType,answer: String): Question(question,type){
    override val isAnswerTrue: String = answer
}

class MultipleChoiceQuestion(question: Int,type: QuestionType,answer: Int,choice1: Int, choice2: Int,choice3: Int,choice4: Int): Question(question,type){
    override val isAnswerTrue: String = answer.toString()
    override val option1: Int = choice1
    override val option2: Int = choice2
    override val option3: Int = choice3
    override val option4: Int = choice4

}