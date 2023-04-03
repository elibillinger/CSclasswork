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

object LocationScreenSpec: IScreenSpec {
    override val route =  "map"
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

        LocationScreen(
            locationState = locationState,
            addressState = addressState,
            onGetLocation = onGetLocation,
            cameraPositionState = cameraPositionState,
            scaffoldState = scaffoldState,
            coroutineScope = coroutineScope,
            viewModel = viewModel,
        )
    }

    override fun navigateTo(vararg args: String?): String {
        return route;
    }
}