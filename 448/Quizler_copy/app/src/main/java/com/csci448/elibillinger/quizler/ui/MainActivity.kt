package com.csci448.elibillinger.quizler.ui

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.csci448.elibillinger.quizler.R
import com.csci448.elibillinger.quizler.data.QuizViewModel
import com.csci448.elibillinger.quizler.data.QuizViewModelFactory

class MainActivity : AppCompatActivity() {
    private lateinit var quizViewModel: QuizViewModel
    companion object {
        private const val LOG_TAG = "448.MainActivity"
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        Log.d(LOG_TAG, "onCreate() called")
        setContentView(R.layout.activity_main)

    }

    override fun onStart() {
        super.onStart()
        Log.d(LOG_TAG, "onStart() called")
    }

    override fun onResume() {
        super.onResume()
        Log.d(LOG_TAG, "onResume() called")
    }

    override fun onPause() {
        super.onPause()
        Log.d(LOG_TAG, "onPause() called")
    }

    override fun onStop() {
        super.onStop()
        Log.d(LOG_TAG, "onStop() called")
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d(LOG_TAG, "onDestroy() called")
    }
}