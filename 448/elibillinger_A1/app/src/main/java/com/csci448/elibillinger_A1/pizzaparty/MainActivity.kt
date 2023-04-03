package com.csci448.elibillinger_A1.pizzaparty

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.*
import androidx.core.widget.doAfterTextChanged


class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        checkValidForButton()
        var recalculate = false
        //check if fields have been updated to check if they are valid
        val refreshCostButton = findViewById<Button>(R.id.refresh_cost_button)
        val numPeopleEditText = findViewById<EditText>(R.id.et_num_people)
        val costPerPizzaEditText = findViewById<EditText>(R.id.et_cost_per_pizza)
        val radioGroup = findViewById<RadioGroup>(R.id.radio_group)
        numPeopleEditText.doAfterTextChanged {
            if(checkValidForButton() && recalculate) {
                calculatePizzaAndCost()
            }
            refreshCostButton.isEnabled = costPerPizzaEditText.text.isNotEmpty()
        }
        costPerPizzaEditText.doAfterTextChanged {
            if(checkValidForButton() && recalculate) {
                calculatePizzaAndCost()
            }
            refreshCostButton.isEnabled = costPerPizzaEditText.text.isNotEmpty()
        }
        radioGroup.setOnCheckedChangeListener { _, _ ->
            if(checkValidForButton() && recalculate) {
                calculatePizzaAndCost()
            }
            refreshCostButton.isEnabled = costPerPizzaEditText.text.isNotEmpty()
        }

        val calculateButton = findViewById<Button>(R.id.calculate_cost_button)
        calculateButton.setOnClickListener {
            if(costPerPizzaEditText.text.isNotEmpty()) {
                recalculate = true
                calculatePizzaAndCost()
            }
            //make cost per pizza, refresh button, and total cost visible
            val costPerPizzaTextView = findViewById<TextView>(R.id.cost_per_pizza_textview)
            costPerPizzaTextView.visibility = View.VISIBLE
            costPerPizzaEditText.visibility = View.VISIBLE
            refreshCostButton.visibility = View.VISIBLE
            val totalCostLabel = findViewById<TextView>(R.id.total_cost_label_textview)
            totalCostLabel.visibility = View.VISIBLE
            val totalCostTextView = findViewById<TextView>(R.id.total_cost_textview)
            totalCostTextView.visibility = View.VISIBLE

        }
        refreshCostButton.setOnClickListener {
            calculatePizzaAndCost()
        }

    }
    private fun calculatePizzaAndCost() {
        val numPeopleEditText = findViewById<EditText>(R.id.et_num_people)
        val radioGroup = findViewById<RadioGroup>(R.id.radio_group)
        val pizzaNeededTextView = findViewById<TextView>(R.id.pizza_needed_textview)
        val numPeople: Int = numPeopleEditText.text.toString().toInt()
        //get value of selected Radio button
        val radioButtonSelected = findViewById<RadioButton>(radioGroup.checkedRadioButtonId)
        //determine total number of slices needed
        val hunger = when (radioButtonSelected.text) {
            "Light" -> 1
            "Medium" -> 2
            "Ravenous" -> 4
            else -> 0
        }
        val numSlices: Int = hunger * numPeople
        // determine number of Pizzas based on 8 slices per pizza
        val numPizzas = when (numSlices % 8) {
            0 -> numSlices / 8
            1 -> (numSlices + 7) / 8
            2 -> (numSlices + 6) / 8
            3 -> (numSlices + 5) / 8
            4 -> (numSlices + 4) / 8
            5 -> (numSlices + 3) / 8
            6 -> (numSlices + 2) / 8
            7 -> (numSlices + 2) / 8
            else -> numSlices / 8
        }
        //update the text for total pizzas needed
        pizzaNeededTextView.text = numPizzas.toString()
        pizzaNeededTextView.visibility = View.VISIBLE
        val costPerPizzaEditText = findViewById<EditText>(R.id.et_cost_per_pizza)

        if(costPerPizzaEditText.text.isNotEmpty()) {
            //get cost per pizza
            val costPerPizza : Float = costPerPizzaEditText.text.toString().toFloat()

            //calculate and update total cost
            val totalCost = numPizzas * costPerPizza
            val totalCostTextView = findViewById<TextView>(R.id.total_cost_textview)
            val totalCostString = "$" + ("%.2f".format(totalCost))
            totalCostTextView.text = totalCostString
        }
    }

    //checks if fields are valid to enable buttons
    private fun checkValidForButton(): Boolean {
        val numPeopleEditText = findViewById<EditText>(R.id.et_num_people)
        val calculateButton = findViewById<Button>(R.id.calculate_cost_button)
        val radioGroup = findViewById<RadioGroup>(R.id.radio_group)
        val refreshCostButton = findViewById<Button>(R.id.refresh_cost_button)

        return if(numPeopleEditText.text.isEmpty() || radioGroup.checkedRadioButtonId == -1){
            calculateButton.isEnabled = false
            refreshCostButton.isEnabled = false
            false
        } else {
            calculateButton.isEnabled = true
            refreshCostButton.isEnabled = true
            true
        }
    }
}