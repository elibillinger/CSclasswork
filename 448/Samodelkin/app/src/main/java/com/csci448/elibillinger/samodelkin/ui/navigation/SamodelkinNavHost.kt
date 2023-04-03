package com.csci448.elibillinger.samodelkin.ui.navigation

import android.util.Log
import androidx.compose.runtime.Composable
import androidx.navigation.NavController
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import com.csci448.elibillinger.samodelkin.ui.navigation.specs.IScreenSpec
import com.csci448.elibillinger.samodelkin.viewmodels.ISamodelkinCharacterViewModel

@Composable
fun SamodelkinNavHost(navController: NavController, viewModel: ISamodelkinCharacterViewModel){
    NavHost(navController = navController as NavHostController , startDestination = IScreenSpec.startDestiniation){
        IScreenSpec.allScreens.forEach{ (route,screen) ->
            if(screen != null){
                    //Log.d("TAG",route.toString())
                    composable(route = route!!){
                        screen.Content(viewModel,navController,it)
                    }
            }
        }
    }
}