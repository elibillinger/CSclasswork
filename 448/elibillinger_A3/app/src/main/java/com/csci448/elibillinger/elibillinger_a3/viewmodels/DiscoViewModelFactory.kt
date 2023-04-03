package com.csci448.elibillinger.elibillinger_a3.viewmodels

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import com.csci448.elibillinger.elibillinger_a3.data.database.DiscoRepository

class DiscoViewModelFactory(private val context: Context) : ViewModelProvider.Factory{
    fun getViewModelClass() = DiscoViewModel::class.java

    override fun<T : ViewModel> create(modelClass: Class<T>): T {
        return modelClass.getConstructor(DiscoRepository::class.java, Context::class.java)
            .newInstance(DiscoRepository.getInstance(context),context)
    }
}