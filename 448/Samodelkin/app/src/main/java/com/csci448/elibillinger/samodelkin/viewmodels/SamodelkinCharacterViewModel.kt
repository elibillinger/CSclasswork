package com.csci448.elibillinger.samodelkin.viewmodels

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.Transformations
import androidx.work.ExistingWorkPolicy
import androidx.work.WorkInfo
import androidx.work.WorkManager
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.data.database.SamodelkinRepository
import com.csci448.elibillinger.samodelkin.util.CharacterGenerator
import com.csci448.elibillinger.samodelkin.util.CharacterWorker
import java.util.*

class SamodelkinCharacterViewModel(private val samodelkinRepository: SamodelkinRepository, context: Context) : ISamodelkinCharacterViewModel() {
    //private val _characterListLiveData = MutableLiveData< MutableList<SamodelkinCharacter> > ( mutableListOf() )

    private val workManager = WorkManager.getInstance(context)

    private val workRequest = CharacterWorker.buildOneTimeWorkRequest()

    override val outputWorkerInfo: LiveData<WorkInfo> =
        workManager.getWorkInfoByIdLiveData(workRequest.id)

    override fun requestWebCharacter() {
        workManager.enqueueUniqueWork(CharacterWorker.UNIQUE_WORK_NAME,
            ExistingWorkPolicy.REPLACE,
            workRequest)
    }

    private val _characterIdLiveData = MutableLiveData<UUID>()

    override val characterListLiveData = samodelkinRepository.getCharacters()

    override val characterLiveData: LiveData<SamodelkinCharacter?> =
        Transformations.switchMap(_characterIdLiveData) { characterId ->
            samodelkinRepository.getCharacter(characterId)
        }

    override fun addCharacter(character: SamodelkinCharacter) {
       samodelkinRepository.addCharacter(character)
    }

    override fun loadCharacter(id: UUID) {
        _characterIdLiveData.value = id
    }

    override fun generateRandomCharacter(): SamodelkinCharacter {
        return CharacterGenerator.generateRandomCharacter()
    }

//    init {
//        for (i in 1..15){
//            addCharacter(generateRandomCharacter())
//        }
//    }
}