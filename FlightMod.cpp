#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "UnityEngine/Rigidbody.hpp"
#include "UnityEngine/Vector3.hpp"

using namespace UnityEngine;

void (*original_Update)(Rigidbody* self);

// This function is called every frame
void Flight_Update(Rigidbody* self) {
    original_Update(self);

    // Constantly apply upward motion to simulate flying
    self->set_velocity(Vector3(0.0f, 5.0f, 0.0f));
}

// Mod setup function (called on init)
extern "C" void setup(ModInfo& info) {
    info.id = "FlightMod";
    info.version = "1.0.0";
    getLogger().info("FlightMod: Setup complete.");
}

// Hook the game's Update function
extern "C" void load() {
    INSTALL_HOOK(getLogger(), Flight_Update);
}
