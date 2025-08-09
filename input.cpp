#include "crow.h"
#include <iostream>
#include <unordered_map>

// Fungsi parsing sederhana body POST urlencoded
std::unordered_map<std::string, std::string> parse_urlencoded(const std::string& body) {
    std::unordered_map<std::string, std::string> params;
    size_t start = 0;

    while (start < body.length()) {
        size_t eq = body.find('=', start);
        if (eq == std::string::npos) break;
        size_t amp = body.find('&', eq);
        std::string key = body.substr(start, eq - start);
        std::string value = (amp == std::string::npos) ? body.substr(eq + 1) : body.substr(eq + 1, amp - eq - 1);

        params[key] = value;
        if (amp == std::string::npos) break;
        start = amp + 1;
    }
    return params;
}

int main() {
    crow::SimpleApp app;

    // form input
    CROW_ROUTE(app, "/")([]() {
        return R"(
            <form action="/submit" method="POST">
                <input type="text" name="user_input" placeholder="Masukkan teks" />
                <button type="submit">Kirim</button>
            </form>
        )";
    });

    // Endpoint 
    CROW_ROUTE(app, "/submit").methods("POST"_method)([](const crow::request& req){
        auto params = parse_urlencoded(req.body);

        std::string input = "";
        auto it = params.find("user_input");
        if (it != params.end()) {
            input = it->second;
        }

        // Tampilkan input di console
        std::cout << "User input: " << input << std::endl;

        return "Input diterima: " + input;
    });

    app.port(18080).multithreaded().run();
}
