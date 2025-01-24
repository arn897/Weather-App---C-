#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
//#include <cpprest/asyncrt_utils.h>
//#include <cpprest/details/basic_types.h>



using namespace std;
using namespace web;
using namespace web::http::client;
//using namespace web::json;
//using namespace utility;


int main() {

	cout << "\t+-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-+" << endl;
	cout << "\t\tMY WEATHER APP" << endl;
	cout << "\t+-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-+" << endl;
	cout << "\tEnter city name: ";
	string city;
	getline(cin, city);


	http_client client(U("https://api.openweathermap.org/data/2.5"));
	uri_builder builder(U("/weather"));
	builder.append_query(U("q"), utility::conversions::to_string_t(city));
	builder.append_query(U("appid"), U("9e4e1301da1b3d7660469de6d3f33d18"));

	web::http::http_request request(web::http::methods::GET);
	request.set_request_uri(builder.to_string());

	client.request(request).then([](web::http::http_response response) {
		return response.extract_json();

		}
	).then([](web::json::value body) {
			cout << "\tTempreature:" << body[U("main")][U("temp")].as_double() << " K " << endl;
			cout << "\tHumidity:" << body[U("main")][U("humidity")].as_double() << "%" << endl;
			cout << "\tWeather:" << utility::conversions::to_utf8string(body[U("weather")][0][U("main")].as_string()) << endl;

		}
		).wait();
		return 0;
}