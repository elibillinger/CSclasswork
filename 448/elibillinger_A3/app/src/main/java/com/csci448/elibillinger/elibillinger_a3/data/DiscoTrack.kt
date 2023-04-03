package com.csci448.elibillinger.elibillinger_a3.data

import androidx.room.Entity
import androidx.room.PrimaryKey
import java.util.*


@Entity(tableName = "track")
class DiscoTrack (
    val albumID: UUID,
    val albumSide: Boolean,
    val trackNum: Int,
    val title: String,
    val lengthMin: Int,
    val lengthSec: Int
        )
{
    @PrimaryKey(autoGenerate = true)
    var id: Int = 0;
}