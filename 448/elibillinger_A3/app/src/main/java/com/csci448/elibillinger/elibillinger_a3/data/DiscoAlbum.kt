package com.csci448.elibillinger.elibillinger_a3.data

import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.*

@Entity(tableName = "album")
class DiscoAlbum (
    val artist : String,
    val title : String,
    val year : Int)
{
    @PrimaryKey
    var id: UUID = UUID.randomUUID()
}