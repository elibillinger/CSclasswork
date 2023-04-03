package com.csci448.elibillinger.lab6.util

import android.content.Context
import androidx.datastore.preferences.core.booleanPreferencesKey
import androidx.datastore.preferences.core.edit
import androidx.datastore.preferences.preferencesDataStore
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.map

class DataStoreManager(private val context: Context) {
    companion object {
        private const val DATA_STORE_NAME = "preferences"
        private val NOTIFICATION_KEY = booleanPreferencesKey("doNotification")
        private val Context.dataStore by preferencesDataStore(
            name = DATA_STORE_NAME
        )
    }
    val doNotificationFlow: Flow<Boolean> = context.dataStore.data
        .map { preferences ->
            preferences[NOTIFICATION_KEY] ?: false
        }

    suspend fun setDoNotification(value: Boolean) {
        context.dataStore.edit { preferences ->
            preferences[NOTIFICATION_KEY] = value
        }
    }
}