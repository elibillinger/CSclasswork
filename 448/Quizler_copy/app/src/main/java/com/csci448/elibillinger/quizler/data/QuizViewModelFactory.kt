package com.csci448.elibillinger.quizler.data

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import java.lang.IllegalArgumentException

class QuizViewModelFactory(private val currentIndex: Int,
                           private val currentScore: Int) : ViewModelProvider.Factory {

    fun getViewModelClass() = QuizViewModel::class.java

    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        if( modelClass.isAssignableFrom(getViewModelClass()) )
            return modelClass.getConstructor(Int::class.java, Int::class.java).
            newInstance(currentIndex, currentScore)
        throw IllegalArgumentException("Unknown ViewModel")
    }
}