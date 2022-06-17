#include "creator/createMaterial.h"

Material createUvMaterial(Context& context, material_t mat ){
    const std::string ptx_path = ptxPath( "uv.cu" );
    Program ch_program = context->createProgramFromPTXFile( ptx_path, "closest_hit_radiance" );
    Program ah_program = context->createProgramFromPTXFile( ptx_path, "any_hit_shadow" );

    Material material = context->createMaterial();
    material->setClosestHitProgram( 0, ch_program );
    material->setAnyHitProgram( 1, ah_program );

    material["uvScale"] -> setFloat(mat.uvScale );
        
    return material; 
}
