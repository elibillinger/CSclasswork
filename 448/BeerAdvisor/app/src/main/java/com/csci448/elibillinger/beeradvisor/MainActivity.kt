package com.csci448.elibillinger.beeradvisor

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Spinner
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val findBeerSpinner = findViewById<Button>(R.id.find_beer_button)
        findBeerSpinner.setOnClickListener{
            val beerColorSpinner = findViewById<Spinner>(R.id.beer_color_spinner)
            val color = beerColorSpinner.selectedItem
            val beerList = getBeers(color.toString())
            val beers = beerList.reduce {str, item ->str + '\n' + item}
            val brandsTextView = findViewById<TextView>(R.id.brands_text_view)
            brandsTextView.text = beers
        }
    }
    fun getBeers(color: String): List<String> {
        return when (color) {
            resources.getString(R.string.color_light) ->
                resources.getStringArray(R.array.beers_light).toList()
            resources.getString(R.string.color_amber) ->
                resources.getStringArray(R.array.beers_amber).toList()
            resources.getString(R.string.color_brown) ->
                resources.getStringArray(R.array.beers_brown).toList()
            resources.getString(R.string.color_dark) ->
                resources.getStringArray(R.array.beers_dark).toList()
            else ->
                resources.getStringArray(R.array.beers_golden).toList()
        }
    }
}