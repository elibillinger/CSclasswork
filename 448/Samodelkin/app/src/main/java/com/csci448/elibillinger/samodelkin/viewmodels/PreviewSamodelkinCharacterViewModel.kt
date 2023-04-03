package com.csci448.elibillinger.samodelkin.viewmodels

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.Transformations
import androidx.work.WorkInfo
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.util.CharacterGenerator
import java.util.*

class PreviewSamodelkinCharacterViewModel private constructor(): ISamodelkinCharacterViewModel() {
    companion object {
        private var instance: PreviewSamodelkinCharacterViewModel? = PreviewSamodelkinCharacterViewModel()
        fun getInstance() : PreviewSamodelkinCharacterViewModel{
            var tempValue = instance
            if (tempValue == null){
                tempValue = PreviewSamodelkinCharacterViewModel()
            }
            instance = tempValue
            return tempValue
        }
    }

    override val outputWorkerInfo: LiveData<WorkInfo> = MutableLiveData()

    private val _characterListLiveData = MutableLiveData< MutableList<SamodelkinCharacter> > ( mutableListOf() )

    private val _characterIdLiveData = MutableLiveData<UUID>()

    override val characterListLiveData: LiveData<MutableList<SamodelkinCharacter>> =
        Transformations.map(_characterListLiveData) { characterList -> characterList}

    override val characterLiveData: LiveData<SamodelkinCharacter?> =    // override the viewmodel interface abstract member
        Transformations.map(_characterIdLiveData) { characterId ->  // transform the character ID live data, characterId is of type UUID
            var foundCharacter: SamodelkinCharacter? = null         // initially assume we haven't found a character
            _characterListLiveData.value?.let { characterList ->    // if the current value is not null - characterList is of type List<SamodelkinCharacter>
                for (character in characterList) {                  // loop through each SamodelkinCharacter
                    if (character.id == characterId) {              // compare IDs
                        foundCharacter = character                  // we found the character
                        break                                       // break the loop
                    }                                               // endif
                }                                                   // endfor
            }                                                       // endlet
            foundCharacter                                          // return what we found (for a lambda expression, the last line is the value returned)
        }

    override fun addCharacter(character: SamodelkinCharacter) {
        _characterListLiveData.value?.let {
                characterList -> characterList.add(character)
            _characterListLiveData.value = characterList
        }
    }

    override fun loadCharacter(id: UUID) {
        _characterIdLiveData.value = id
    }

    override fun generateRandomCharacter(): SamodelkinCharacter {
        return CharacterGenerator.generateRandomCharacter()
    }

    override fun requestWebCharacter() { }

    init {
        for (i in 1..15){
            addCharacter(generateRandomCharacter())
        }
    }
}

