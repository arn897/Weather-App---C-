# Weather-App---C-

Overview
This is a simple command-line Weather App built in C++ that fetches weather data from the OpenWeatherMap API. It allows users to enter a city name and retrieve the temperature, humidity, and weather condition for that city.

Features
Fetches weather data using the OpenWeatherMap API.
Displays temperature (in Kelvin), humidity percentage, and weather condition.
Simple command-line interface for user input and output.

Prerequisites
To run this program, you'll need:

A C++ compiler (e.g., GCC, Clang).
The C++ REST SDK (also known as cpprestsdk), which is used for HTTP requests and JSON parsing.
A valid OpenWeatherMap API key.

Install C++ REST SDK
You can follow the installation guide for the C++ REST SDK here: https://github.com/microsoft/cpprestsdk

Alternatively, if you are using Linux, you can install the C++ REST SDK via a package manager:

On Ubuntu/Debian:
bash
Copy
Edit
sudo apt-get install libcpprest-dev

API Key
To use the OpenWeatherMap API, you need to sign up at https://openweathermap.org/ and get an API key. Replace the placeholder key in the code with your own API key:

cpp
Copy
Edit
builder.append_query(U("appid"), U("YOUR_API_KEY"));
How to Use
Clone or download this repository.

Compile the C++ file using your preferred compiler. Example (GCC):

bash
Copy
Edit
g++ -std=c++11 weather.cpp -o weather -lcpprest
Run the program:

bash
Copy
Edit
./weather
Enter the name of the city when prompted. Example input: London

The app will display the weather information for the entered city:

Temperature (in Kelvin)
Humidity (percentage)
Weather condition (e.g., clear sky, rain, etc.)
Example Output
yaml
Copy
Edit
	+-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-+
		MY WEATHER APP
	+-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-+
	Enter city name: London
		Temperature: 293.15 K
		Humidity: 75.0 %
		Weather: Clear sky

Code Explanation
User Input: The user is prompted to enter a city name.
API Request: The program makes a GET request to the OpenWeatherMap API with the entered city and the API key.
JSON Parsing: The response is parsed in JSON format to extract the temperature, humidity, and weather condition.
Display Output: The extracted data is displayed in a user-friendly format.


Contributing
Feel free to fork the repository, create issues, and submit pull requests. Contributions are welcome!
