package com.csci448.elibillinger.elibillinger_a3.ui.navigation

import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.navigation.NavController
import androidx.navigation.compose.currentBackStackEntryAsState
import com.csci448.elibillinger.elibillinger_a3.ui.navigation.specs.IScreenSpec

@Composable
fun DiscoTopBar(navController: NavController){
    val navBackStackEntry by navController.currentBackStackEntryAsState()

    IScreenSpec.TopBar(navController, navBackStackEntry)
}