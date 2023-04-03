package com.csci448.elibillinger.samodelkin.viewmodels

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.work.WorkInfo
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import java.util.*

abstract class ISamodelkinCharacterViewModel: ViewModel() {
    abstract val characterListLiveData: LiveData<MutableList<SamodelkinCharacter>>
    abstract val characterLiveData: LiveData<SamodelkinCharacter?>
    abstract val outputWorkerInfo: LiveData<WorkInfo>

    abstract fun addCharacter(character: SamodelkinCharacter)
    abstract fun loadCharacter(id: UUID)
    abstract fun generateRandomCharacter(): SamodelkinCharacter
    abstract fun requestWebCharacter()

}