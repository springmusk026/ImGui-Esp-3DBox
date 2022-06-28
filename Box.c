void Draw3dBox(ImDrawList *draw,Vector3 Transform,void * camera,int glHeight,int glWidth)
{
    Vector3 position2 = Transform + Vector3(0.6, 1.6, 0.6); 
    Vector3 position3 = Transform + Vector3(0.6, 0, 0.6);
    Vector3 position4 = Transform + Vector3(-0.5, 0, 0.6); 
    Vector3 position5 = Transform + Vector3(-0.5, 1.6, 0.6);
    Vector3 position6 = (Transform + Vector3(0.6, 1.6, 0)) + Vector3(0, 0, -0.6);
    Vector3 position7 = (Transform + Vector3(0.6, 0, 0)) + Vector3(0, 0, -0.6);
    Vector3 position8 = (Transform + Vector3(-0.5, 0, 0)) + Vector3(0, 0, -0.6); 
    Vector3 position9 = (Transform + Vector3(-0.5, 1.6, 0)) + Vector3(0, 0, -0.6);

    Vector3 vector = WorldToScreenPoint(camera, position2);
    Vector3 vector2 = WorldToScreenPoint(camera, position3);
    Vector3 vector3 = WorldToScreenPoint(camera, position4);
    Vector3 vector4 = WorldToScreenPoint(camera, position5);
    Vector3 vector5 = WorldToScreenPoint(camera, position6);
    Vector3 vector6 = WorldToScreenPoint(camera, position7);
    Vector3 vector7 = WorldToScreenPoint(camera, position8);
    Vector3 vector8 = WorldToScreenPoint(camera, position9);

    if (vector.Z > 0 && vector2.Z > 0 && vector3.Z > 0 && vector4.Z > 0 && vector5.Z > 0 && vector6.Z > 0 && vector7.Z > 0 && vector8.Z > 0 )
    {
        draw->AddLine({(float) (glWidth -(glWidth -vector.X)),(glHeight -vector.Y)}, {glWidth - (glWidth - vector2.X),glHeight -vector2.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector3.X)),(glHeight -vector3.Y)}, {glWidth - (glWidth - vector2.X),glHeight -vector2.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector.X)),(glHeight -vector.Y)}, {glWidth - (glWidth - vector4.X),glHeight -vector4.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector4.X)),(glHeight -vector4.Y)}, {glWidth - (glWidth - vector3.X),glHeight -vector3.Y}, ToColor(configs.esp.ESPColor), 2.0f);

        draw->AddLine({(float) (glWidth -(glWidth -vector5.X)),(glHeight -vector5.Y)}, {glWidth - (glWidth - vector6.X),glHeight -vector6.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector7.X)),(glHeight -vector7.Y)}, {glWidth - (glWidth - vector6.X),glHeight -vector6.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector5.X)),(glHeight -vector5.Y)}, {glWidth - (glWidth - vector8.X),glHeight -vector8.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector8.X)),(glHeight -vector8.Y)}, {glWidth - (glWidth - vector7.X),glHeight -vector7.Y}, ToColor(configs.esp.ESPColor), 2.0f);

        draw->AddLine({(float) (glWidth -(glWidth -vector.X)),(glHeight -vector.Y)}, {glWidth - (glWidth - vector5.X),glHeight -vector5.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector2.X)),(glHeight -vector2.Y)}, {glWidth - (glWidth - vector6.X),glHeight -vector6.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector3.X)),(glHeight -vector3.Y)}, {glWidth - (glWidth - vector7.X),glHeight -vector7.Y}, ToColor(configs.esp.ESPColor), 2.0f);
        draw->AddLine({(float) (glWidth -(glWidth -vector4.X)),(glHeight -vector4.Y)}, {glWidth - (glWidth - vector8.X),glHeight -vector8.Y}, ToColor(configs.esp.ESPColor), 2.0f);
    
    }
}
