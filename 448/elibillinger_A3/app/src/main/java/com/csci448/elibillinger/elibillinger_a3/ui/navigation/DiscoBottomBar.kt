package com.csci448.elibillinger.elibillinger_a3.ui.navigation

import androidx.compose.material.BottomNavigation
import androidx.compose.material.BottomNavigationItem
import androidx.compose.material.Icon
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.ui.res.painterResource
import androidx.navigation.NavController
import androidx.navigation.compose.currentBackStackEntryAsState
import com.csci448.elibillinger.elibillinger_a3.R

@Composable
fun DiscoBottomBar(navController: NavController){
    val navBackStackEntry by navController.currentBackStackEntryAsState()
    val currentRoute = navBackStackEntry?.destination?.route
    BottomNavigation {
        //Albums Nav Item
        BottomNavigationItem(
            label = { Text(text = "Albums")},
            icon = { Icon(painter = painterResource(id = R.drawable.ic_baseline_library_music_24), contentDescription = "Go to Album List") },
            selected = currentRoute == "albums",
            onClick = { navController.navigate("albums") })
        //Tracks Nav Item
        BottomNavigationItem(
            label = { Text(text = "Tracks")},
            icon = { Icon(painter = painterResource(id = R.drawable.ic_baseline_music_note_24), contentDescription = "Go to Track List") },
            selected = currentRoute == "tracks",
            onClick = { navController.navigate("tracks") })
    }
}