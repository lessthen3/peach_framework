/*******************************************************************
 *                        Peach-E v0.0.1
 *         Created by Ranyodh Singh Mandur - 🍑 2024-2026
 *
 *              Licensed under the MIT License (MIT).
 *         For more details, see the LICENSE file or visit:
 *               https://opensource.org/licenses/MIT
 *
 *           Peach-E is a free open source game engine
********************************************************************/
#pragma once

///PeachCore
#include "Utils/Serializer.h"

///GLM
#include <glm/glm.hpp>

///STL
#include <string>

namespace PeachCore
{
    using namespace std;

    //for longer lived pure data sources, ID's are helpful for locating them on the gpu or PCM audio
    template<typename Tag>
    struct TypedID //this will be thrown out by the compiler probably but its still stack alloc'd so wont be that bad owo, but the type checking at compile time is useful owo
    {
        uint64_t Value = 0;

        TypedID() = default;
        explicit TypedID(uint64_t fp_Value) : Value(fp_Value) {}

        bool operator==(const TypedID&) const noexcept = default;
        bool operator!=(const TypedID&) const noexcept = default;
        explicit operator bool() const noexcept { return Value != 0; }
    };

    struct TextureTag {}; //compile time convenience owo c++ should have aliases for this, this is how i thought typedef worked originally but eh owo
    struct MeshTag {};
    struct AudioTag {};
    struct AnimationTag {};

    using TextureID = TypedID<TextureTag>;
    using MeshID = TypedID<MeshTag>;
    using AudioID = TypedID<AudioTag>;
    using AnimationID = TypedID<AnimationTag>;

    struct Vertex
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 UV;
        glm::vec4 Tangent; // vec4 because the w component stores the bitangent handedness sign
    };

    struct Material
    {

    };

    struct PBRMaterial
    {
        glm::vec4 AlbedoColor;
        float Roughness;
        float Metallic;
        float AO;
        float EmissiveStrength;
    };

    struct MeshData 
    {
        vector<Vertex> Vertices;
        vector<uint32_t> Indices;
        // material ids etc.
    };

    struct Bone
    {
        string Name;
        int ParentIndex;
        glm::mat4 OffsetMatrix;
    };

    struct AnimationKeyframe
    {
        float Time;
        // transforms per bone…
    };

    struct AnimationClip 
    {
        string Name;
        float Duration;
        vector<AnimationKeyframe> Keyframes;
    };

    struct AnimationData 
    {
        vector<Bone> Bones;
        vector<AnimationClip> Clips;
    };
}
