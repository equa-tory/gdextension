#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &GDExample::set_speed);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("get_message"), &GDExample::get_message);
    ClassDB::bind_method(D_METHOD("set_message", "p_message"), &GDExample::set_message);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "message"), "set_message", "get_message");
}

GDExample::GDExample() {
	// Initialize any variables here.
	time_passed = 0.0;
    speed = 10.0;
}

GDExample::~GDExample() {
	// Add your cleanup here.
}

void GDExample::_process(double delta) {

    if(Engine::get_singleton()->is_editor_hint()) return;
	
    time_passed += delta;

	Vector2 new_position = Vector2(
		speed + (speed * sin(time_passed * 2.0)),
		speed + (speed * cos(time_passed * 1.5))
	);

    UtilityFunctions::print("[MSG] "+message);
	set_position(new_position);
}

void GDExample::set_speed(const double p_speed) {
	speed = p_speed;
}

double GDExample::get_speed() const {
	return speed;
}

void GDExample::set_message(const String p_message)
{
    message = p_message;
}
String GDExample::get_message() const
{
    return message;
}