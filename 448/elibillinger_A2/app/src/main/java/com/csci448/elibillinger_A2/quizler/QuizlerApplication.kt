package com.csci448.elibillinger_A2.quizler

import android.app.Application
import android.content.res.Configuration
import android.content.res.Configuration.ORIENTATION_LANDSCAPE
import android.content.res.Configuration.ORIENTATION_PORTRAIT
import android.util.Log

class QuizlerApplication : Application() {
    companion object {
        private const val LOG_TAG = "448.QuizlerApplication"
    }
    override fun onCreate() {
        super.onCreate()
        Log.d(LOG_TAG, "onCreate() called")
    }

    override fun onConfigurationChanged(newConfig: Configuration) {
        super.onConfigurationChanged(newConfig)
        Log.d(LOG_TAG, "onConfigurationChanged() called")
        Log.d(LOG_TAG, "orientation is ${
            when(newConfig.orientation) {
                ORIENTATION_LANDSCAPE -> "Landscape"
                ORIENTATION_PORTRAIT -> "Portrait"
                else                 -> "Undefined"
            }}")
    }
}