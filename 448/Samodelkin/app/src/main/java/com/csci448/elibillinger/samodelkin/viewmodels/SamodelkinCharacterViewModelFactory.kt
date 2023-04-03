package com.csci448.elibillinger.samodelkin.viewmodels

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.ViewModelStoreOwner
import com.csci448.elibillinger.samodelkin.data.database.SamodelkinRepository
import java.lang.IllegalArgumentException

class SamodelkinCharacterViewModelFactory(private val context: Context) : ViewModelProvider.Factory {
    fun getViewModelClass() = SamodelkinCharacterViewModel::class.java

    override fun<T : ViewModel> create(modelClass: Class<T>): T {
            return modelClass.getConstructor(SamodelkinRepository::class.java, Context::class.java)
                .newInstance(SamodelkinRepository.getInstance(context),context)
    }
}