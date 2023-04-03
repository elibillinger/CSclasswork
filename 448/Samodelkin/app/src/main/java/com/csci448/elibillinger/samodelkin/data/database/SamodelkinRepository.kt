package com.csci448.elibillinger.samodelkin.data.database

import android.content.Context
import androidx.lifecycle.LiveData
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import java.util.*
import java.util.concurrent.Executors

class SamodelkinRepository private constructor(private val samodelkinDao: SamodelkinDao) {
    companion object{
        @Volatile private var INSTANCE: SamodelkinRepository? = null
        fun getInstance(context: Context): SamodelkinRepository {
            synchronized(this) {
                var instance = INSTANCE
                if(instance == null) {
                    val database = SamodelkinDatabase.getInstance(context)
                    instance = SamodelkinRepository(database.samodelkinDao)
                    INSTANCE = instance
                }
                return instance
            }
        }
    }

    private val executor = Executors.newSingleThreadExecutor()

    fun addCharacter(character: SamodelkinCharacter){
        executor.execute{
            samodelkinDao.addCharacter(character)
        }
    }
    fun getCharacters(): LiveData<MutableList<SamodelkinCharacter>> = samodelkinDao.getCharacters()
    fun getCharacter(id: UUID): LiveData<SamodelkinCharacter?> = samodelkinDao.getCharacter(id)
}