package com.csci448.elibillinger.lab6

import android.location.Location
import androidx.compose.material.ScaffoldState
import androidx.compose.runtime.Composable
import androidx.compose.runtime.State
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.google.maps.android.compose.CameraPositionState
import kotlinx.coroutines.CoroutineScope

object SettingsScreenSpec: IScreenSpec {
    override val route =  "settings"
    override val arguments: List<NamedNavArgument> = listOf()

    @Composable
    override fun Content(locationState : State<Location?>,
                         onGetLocation: () -> Unit,
                         addressState: State<String>,
                         cameraPositionState: CameraPositionState,
                         scaffoldState: ScaffoldState,
                         coroutineScope: CoroutineScope,
                         viewModel: GeoLocatrViewModel,
                         navController: NavController,
                         navBackStackEntry: NavBackStackEntry
    ) {

        SettingsScreen()
    }

    override fun navigateTo(vararg args: String?): String {
        return route;
    }
}