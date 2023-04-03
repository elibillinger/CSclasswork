package com.csci448.elibillinger.lab6

import android.location.Location
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.runtime.Composable
import androidx.compose.runtime.State
import androidx.compose.ui.res.stringResource
import androidx.navigation.NamedNavArgument
import androidx.navigation.NavBackStackEntry
import androidx.navigation.NavController
import com.google.maps.android.compose.CameraPositionState
import kotlinx.coroutines.CoroutineScope

sealed interface IScreenSpec {
    companion object {
        val startDestiniation: String = LocationScreenSpec.route
        val allScreens = IScreenSpec::class.sealedSubclasses.associate { it.objectInstance?.route to it.objectInstance }
    }

    val route: String
    val arguments: List<NamedNavArgument>
    @Composable
    fun Content(locationState : State<Location?>,
                onGetLocation: () -> Unit,
                addressState: State<String>,
                cameraPositionState: CameraPositionState,
                scaffoldState: ScaffoldState,
                coroutineScope: CoroutineScope,
                viewModel: GeoLocatrViewModel,
                navController: NavController,
                navBackStackEntry: NavBackStackEntry
    )

    fun navigateTo(vararg args: String?):String


}

