#include "creator/createMaterial.h"

Material createMatPartMaterial(Context& context, int modelId, int matId, int shapeId ){
    const std::string ptx_path = ptxPath( "matPart.cu" );
    Program ch_program = context->createProgramFromPTXFile( ptx_path, "closest_hit_radiance" );
    Program ah_program = context->createProgramFromPTXFile( ptx_path, "any_hit_shadow" );

    Material material = context->createMaterial();
    material->setClosestHitProgram( 0, ch_program );
    material->setAnyHitProgram( 1, ah_program );
    
    material["modelId"] -> setInt(modelId );
    material["matId"] -> setInt(matId );
    material["shapeId"] -> setInt(shapeId );

    return material; 
}
