void Draw3dBox(ImDrawList* draw, Vector3 origin, void* camera, int screenHeight, int screenWidth) {
    // Define the 8 corners of the box in 3D space (relative to origin)
    Vector3 topFrontRight     = origin + Vector3(0.6f, 1.6f,  0.6f);
    Vector3 bottomFrontRight  = origin + Vector3(0.6f, 0.0f,  0.6f);
    Vector3 bottomFrontLeft   = origin + Vector3(-0.5f, 0.0f, 0.6f);
    Vector3 topFrontLeft      = origin + Vector3(-0.5f, 1.6f, 0.6f);

    Vector3 topBackRight      = origin + Vector3(0.6f, 1.6f, -0.0f) + Vector3(0.0f, 0.0f, -0.6f);
    Vector3 bottomBackRight   = origin + Vector3(0.6f, 0.0f, -0.0f) + Vector3(0.0f, 0.0f, -0.6f);
    Vector3 bottomBackLeft    = origin + Vector3(-0.5f, 0.0f, -0.0f) + Vector3(0.0f, 0.0f, -0.6f);
    Vector3 topBackLeft       = origin + Vector3(-0.5f, 1.6f, -0.0f) + Vector3(0.0f, 0.0f, -0.6f);

    // Convert to screen space
    Vector3 screen[8] = {
        WorldToScreenPoint(camera, topFrontRight),
        WorldToScreenPoint(camera, bottomFrontRight),
        WorldToScreenPoint(camera, bottomFrontLeft),
        WorldToScreenPoint(camera, topFrontLeft),
        WorldToScreenPoint(camera, topBackRight),
        WorldToScreenPoint(camera, bottomBackRight),
        WorldToScreenPoint(camera, bottomBackLeft),
        WorldToScreenPoint(camera, topBackLeft)
    };

    // Ensure all points are in front of the camera
    for (int i = 0; i < 8; i++) {
        if (screen[i].Z <= 0)
            return;
    }

    // Helper lambda to convert Vector3 to ImVec2 (screen space)
    auto toScreen = [&](const Vector3& v) -> ImVec2 {
        return ImVec2(v.X, screenHeight - v.Y);
    };

    ImColor color = ToColor(configs.esp.ESPColor);
    float thickness = 2.0f;

    // Front face
    draw->AddLine(toScreen(screen[0]), toScreen(screen[1]), color, thickness); // TopRight - BottomRight
    draw->AddLine(toScreen(screen[1]), toScreen(screen[2]), color, thickness); // BottomRight - BottomLeft
    draw->AddLine(toScreen(screen[2]), toScreen(screen[3]), color, thickness); // BottomLeft - TopLeft
    draw->AddLine(toScreen(screen[3]), toScreen(screen[0]), color, thickness); // TopLeft - TopRight

    // Back face
    draw->AddLine(toScreen(screen[4]), toScreen(screen[5]), color, thickness); // TopRight - BottomRight
    draw->AddLine(toScreen(screen[5]), toScreen(screen[6]), color, thickness); // BottomRight - BottomLeft
    draw->AddLine(toScreen(screen[6]), toScreen(screen[7]), color, thickness); // BottomLeft - TopLeft
    draw->AddLine(toScreen(screen[7]), toScreen(screen[4]), color, thickness); // TopLeft - TopRight

    // Connect front and back faces
    draw->AddLine(toScreen(screen[0]), toScreen(screen[4]), color, thickness); // TopFrontRight - TopBackRight
    draw->AddLine(toScreen(screen[1]), toScreen(screen[5]), color, thickness); // BottomFrontRight - BottomBackRight
    draw->AddLine(toScreen(screen[2]), toScreen(screen[6]), color, thickness); // BottomFrontLeft - BottomBackLeft
    draw->AddLine(toScreen(screen[3]), toScreen(screen[7]), color, thickness); // TopFrontLeft - TopBackLeft
}
