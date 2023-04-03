package com.csci448.elibillinger.samodelkin.data

import androidx.room.Entity
import androidx.room.PrimaryKey
import java.io.Serializable
import java.util.*

@Entity(tableName = "character")
class SamodelkinCharacter (val name: String,
                           val race: String,
                           val dex: String,
                           val str: String,
                           val wis: String): Serializable{
    @PrimaryKey var id: UUID = UUID.randomUUID()
}