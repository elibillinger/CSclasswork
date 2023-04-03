package com.csci448.elibillinger.lab6

import android.location.Location
import androidx.compose.material.ScaffoldState
import androidx.compose.runtime.Composable
import androidx.compose.runtime.State
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.NavHostController
import androidx.navigation.compose.composable
import com.google.maps.android.compose.CameraPositionState
import kotlinx.coroutines.CoroutineScope

@Composable
fun WeatherNavHost(locationState : State<Location?>,
                   onGetLocation: () -> Unit,
                   addressState: State<String>,
                   cameraPositionState: CameraPositionState,
                   scaffoldState: ScaffoldState,
                   coroutineScope: CoroutineScope, navController: NavController, viewModel: GeoLocatrViewModel){
    NavHost(navController = navController as NavHostController, startDestination = IScreenSpec.startDestiniation){
        IScreenSpec.allScreens.forEach{ (route,screen) ->
            if(screen != null){
                //Log.d("TAG",route.toString()
                composable(route = route!!){
                    screen.Content(locationState,onGetLocation,addressState,cameraPositionState,scaffoldState,coroutineScope,viewModel,navController,it)
                }
            }
        }
    }
}