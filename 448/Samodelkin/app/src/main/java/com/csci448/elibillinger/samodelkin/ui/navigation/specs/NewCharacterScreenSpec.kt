package com.csci448.elibillinger.samodelkin.ui.navigation.specs

import android.util.Log
import androidx.compose.runtime.Composable
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.saveable.rememberSaveable
import androidx.core.content.PackageManagerCompat.LOG_TAG
import androidx.navigation.*
import androidx.work.WorkInfo
import com.csci448.elibillinger.samodelkin.R
import com.csci448.elibillinger.samodelkin.data.SamodelkinCharacter
import com.csci448.elibillinger.samodelkin.ui.screens.NewCharacterScreen
import com.csci448.elibillinger.samodelkin.util.CharacterWorker
import com.csci448.elibillinger.samodelkin.viewmodels.ISamodelkinCharacterViewModel

object NewCharacterScreenSpec: IScreenSpec {
    override val title = R.string.app_name
    override val route = "new"
    override val arguments: List<NamedNavArgument> = listOf()
    private const val LOG_TAG = "448.CharacterWorker"

    override fun navigateTo(vararg args: String?): String {
        return route
    }

    @Composable
    override fun TopAppBarActions(navController: NavController) {
       //nothing
    }

    @Composable
    override fun Content(viewModel: ISamodelkinCharacterViewModel,
                         navController: NavController,
                         navBackStackEntry: NavBackStackEntry
    ){
        val characterState = rememberSaveable {
            mutableStateOf( viewModel.generateRandomCharacter() )
        }
        val workInfoState = viewModel.outputWorkerInfo.observeAsState()
        workInfoState.value?.let { workInfo ->
            when(workInfo.state) {
                WorkInfo.State.ENQUEUED -> Log.d(LOG_TAG, "workInfo enqueued")
                WorkInfo.State.RUNNING -> Log.d(LOG_TAG, "workInfo running")
                WorkInfo.State.SUCCEEDED -> {
                    Log.d(LOG_TAG, "workInfo succeeded")
                    val apiData = CharacterWorker.getApiData( workInfo.outputData )
                    Log.d(LOG_TAG, "Got api data $apiData")
                    if(apiData != null) {
                        val (race, name, dex, wis, str) = apiData.split(",")
                        val apiCharacter = SamodelkinCharacter(name, race, dex, wis, str )
                        characterState.value = apiCharacter
                    } else {
                    Log.d(LOG_TAG, "no data")
                    }
                }
                else -> Log.d(LOG_TAG, "other workInfo state")
            }
        }
        NewCharacterScreen(
            characterState = characterState,
            onGenerateRandomCharacter = { characterState.value = viewModel.generateRandomCharacter() },
            onRequestApiCharacter = { viewModel.requestWebCharacter() }
        ) { character ->
            viewModel.addCharacter(character)
            navController.popBackStack()
        }
    }
}