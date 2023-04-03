package com.csci448.elibillinger.lab6.util

import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.graphics.Color
import android.location.Location
import androidx.compose.ui.res.stringResource
import androidx.core.app.NotificationCompat
import androidx.core.app.NotificationManagerCompat
import com.csci448.elibillinger.lab6.MainActivity
import com.csci448.elibillinger.lab6.R

object LocationNotificationUtility {

    fun pushNotification(context: Context,location: Location){
        val notificationManager = NotificationManagerCompat.from(context)
        val channelID = "geoLocatrChannelID"
        val name = context.resources.getString(R.string.app_name)
        val importance = NotificationManager.IMPORTANCE_DEFAULT
        val channel = NotificationChannel( channelID, name, importance ).apply{
            description = context.resources.getString(R.string.notification_channel_desc)
        }
        notificationManager.createNotificationChannel(channel)

        val pendingIntent = MainActivity.createPendingIntent(context,location)
        val notification = NotificationCompat.Builder(context, channelID)
            .setSmallIcon(android.R.drawable.ic_dialog_map) // REQUIRED!
            .setContentTitle(context.resources.getString(R.string.notification_title))
            .setContentText(context.resources.getString(R.string.notification_content_text).format(location.latitude.toString() , location.longitude.toString()))
            .setContentIntent(pendingIntent)
            .setAutoCancel(true)  // remove notification when user selects
            .build()  // make the actual notification
        notificationManager.notify(0, notification)

    }


}