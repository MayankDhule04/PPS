# PPS
1. Capture and Validate Input
To capture input, we use EditText for text fields (Expense Title and Amount) and a Spinner for selecting the expense category. Validation ensures that all fields are filled out correctly before proceeding.

Expense Title and Amount are checked to ensure they are not empty.


Amount is validated to ensure it is a valid number.


Category is automatically validated by ensuring a selection is made from the Spinner.

In the Add Expense button's click listener, we use:
if (title.isEmpty() || amountText.isEmpty()) {
    Toast.makeText(ExpenseActivity.this, "Please fill all fields", Toast.LENGTH_SHORT).show();
}
This simple check ensures no user input is missed.
2. Categorize Expenses
To categorize expenses, a Spinner is used to let users choose an expense category (like Food, Transport, Entertainment, etc.). The categories are pre-defined in the strings.xml file and are populated in the spinner via an ArrayAdapter.
ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,
        R.array.expense_categories, android.R.layout.simple_spinner_item);
categorySpinner.setAdapter(adapter);
When the user selects a category from the spinner, it’s retrieved with categorySpinner.getSelectedItem().toString(). This allows users to specify the type of expense for better organization.
3. Insert into SQLite
To store the expense data into a SQLite database, we create a helper class extending SQLiteOpenHelper to manage the database. When the user adds an expense, the data is inserted into a database table.
// Example function to insert data into SQLite
public void insertExpense(String title, double amount, String category) {
    SQLiteDatabase db = dbHelper.getWritableDatabase();
    ContentValues values = new ContentValues();
    values.put("title", title);
    values.put("amount", amount);
    values.put("category", category);
    db.insert("expenses", null, values);
    db.close();
}
This stores the expense details in a table, allowing them to be retrieved later.
4. Display Success Message
After inserting the expense into SQLite, a success message is shown to the user using a Toast.
Toast.makeText(ExpenseActivity.this, "Expense Added", Toast.LENGTH_SHORT).show();
This provides immediate feedback to the user, letting them know the data has been successfully saved.
Justification:
By capturing and validating input, we ensure the data entered is correct and meaningful. Categorizing expenses helps the user track their spending more effectively by organizing data. Storing the expenses in SQLite ensures persistence, meaning the data will be saved even if the app is closed. Displaying a success message reassures the user that their action was completed successfully. This approach makes the app user-friendly, reliable, and efficient for real-world usage where users need to track, organize, and manage their finances.
