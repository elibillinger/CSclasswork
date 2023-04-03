package com.csci448.elibillinger.elibillinger_a3.ui.navigation

import androidx.compose.runtime.Composable
import androidx.navigation.NavController
import androidx.navigation.NavHostController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs.IScreenSpec
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

@Composable
fun DiscoNavHost(navController: NavController, viewModel: IDiscoViewModel){
    NavHost(navController = navController as NavHostController , startDestination = IScreenSpec.startDestiniation){
        IScreenSpec.allScreens.forEach{ (route,screen) ->
            if(screen != null){
                composable(route = route!!){
                    screen.Content(viewModel,navController,it)
                }
            }
        }
    }
}