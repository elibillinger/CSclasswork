package com.csci448.elibillinger.elibillinger_a3

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Scaffold
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.lifecycle.ViewModelProvider
import androidx.navigation.compose.rememberNavController
import com.csci448.elibillinger.elibillinger_a3.ui.navigation.DiscoBottomBar
import com.csci448.elibillinger.elibillinger_a3.ui.navigation.DiscoNavHost
import com.csci448.elibillinger.elibillinger_a3.ui.navigation.DiscoTopBar
import com.csci448.elibillinger.elibillinger_a3.ui.theme.Elibillinger_A3Theme
import com.csci448.elibillinger.elibillinger_a3.viewmodels.DiscoViewModel
import com.csci448.elibillinger.elibillinger_a3.viewmodels.DiscoViewModelFactory
import com.csci448.elibillinger.elibillinger_a3.viewmodels.IDiscoViewModel

class MainActivity : ComponentActivity() {

    private lateinit var viewModel: DiscoViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        //set up viewModel
        val factory = DiscoViewModelFactory(this)
        viewModel = ViewModelProvider(this,factory).get(factory.getViewModelClass())
        setContent {
            MainActivityContent(viewModel = viewModel)
        }
    }
}

@Composable
fun MainActivityContent(viewModel: IDiscoViewModel) {
    val navController = rememberNavController()
    Elibillinger_A3Theme {
        Surface(
            modifier = Modifier.fillMaxSize(),
            color = MaterialTheme.colors.background
        ) {
            Scaffold (
                topBar = { DiscoTopBar(navController = navController)},
                content = {DiscoNavHost(navController = navController, viewModel = viewModel)},
                bottomBar = { DiscoBottomBar(navController = navController)}
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    Elibillinger_A3Theme {
        //Greeting("Android")
    }
}