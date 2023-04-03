package com.csci448.elibillinger.samodelkin.data.database

import androidx.lifecycle.LiveData
import androidx.room.Dao
import androidx.room.Insert
import androidx.room.Query
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import java.util.*

@Dao
interface SamodelkinDao {
    @Insert
    fun addCharacter(character: SamodelkinCharacter)
    @Query("SELECT * FROM character")
    fun getCharacters(): LiveData<MutableList<SamodelkinCharacter>>
    @Query("SELECT * FROM character WHERE id=(:id)")
    fun getCharacter(id: UUID) : LiveData<SamodelkinCharacter?>
}