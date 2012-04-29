const char* PIXEL_SHADER =
"static const float2 INPUT_SIZE = float2(480.0f, 272.0f);\n"
"\n"
"sampler2D textureSampler;\n"
"float2 outputSize;\n"
"\n"
"float spline36_0_1(float x) {\n"
"return 13.0f / 11.0f * x * x * x - 453.0f / 209.0f * x * x - 3.0f / 209.0f * x + 1.0f;\n"
"}\n"
"\n"
"float spline36_1_2(float x) {\n"
"return -6.0f / 11.0f * x * x * x + 612.0f / 209.0f * x * x - 1038.0f / 209.0f * x + 540.0f / 209.0f;\n"
"}\n"
"\n"
"float spline36_2_3(float x) {\n"
"return 1.0f / 11.0f * x * x * x - 159.0f / 209.0f * x * x + 434.0f / 209.0f * x - 384.0f / 209.0f;\n"
"}\n"
"\n"
"float4 rgb(float inputX, float inputY) {\n"
"return tex2D(textureSampler, float2(inputX + 0.5f, inputY + 0.5f) / INPUT_SIZE);\n"
"}\n"
"\n"
"float4 interpolateHorizontally(float2 inputPos, int2 inputPosFloor, int dy) {\n"
"float sumOfWeights = 0.0f;\n"
"float4 sumOfWeightedPixel = 0.0f;\n"
"\n"
"float weight;\n"
"\n"
"weight = spline36_2_3(inputPos.x - (inputPosFloor.x - 2));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x - 2, inputPosFloor.y + dy);\n"
"\n"
"weight = spline36_1_2(inputPos.x - (inputPosFloor.x - 1));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x - 1, inputPosFloor.y + dy);\n"
"\n"
"weight = spline36_0_1(inputPos.x - (inputPosFloor.x + 0));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x + 0, inputPosFloor.y + dy);\n"
"\n"
"weight = spline36_0_1((inputPosFloor.x + 1) - inputPos.x);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x + 1, inputPosFloor.y + dy);\n"
"\n"
"weight = spline36_1_2((inputPosFloor.x + 2) - inputPos.x);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x + 2, inputPosFloor.y + dy);\n"
"\n"
"weight = spline36_2_3((inputPosFloor.x + 3) - inputPos.x);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * rgb(inputPosFloor.x + 3, inputPosFloor.y + dy);\n"
"\n"
"return sumOfWeightedPixel / sumOfWeights;\n"
"}\n"
"\n"
"float4 process(float2 outputPos : VPOS) : COLOR0 {\n"
"float2 inputPos = outputPos / outputSize * INPUT_SIZE;\n"
"int2 inputPosFloor = (int2)inputPos;\n"
"\n"
"// Horizontal interpolation.\n"
"float4 vertical[6] = {\n"
"interpolateHorizontally(inputPos, inputPosFloor, -2),\n"
"interpolateHorizontally(inputPos, inputPosFloor, -1),\n"
"interpolateHorizontally(inputPos, inputPosFloor, +0),\n"
"interpolateHorizontally(inputPos, inputPosFloor, +1),\n"
"interpolateHorizontally(inputPos, inputPosFloor, +2),\n"
"interpolateHorizontally(inputPos, inputPosFloor, +3),\n"
"};\n"
"\n"
"// Vertical interporation\n"
"float sumOfWeights = 0.0;\n"
"float4 sumOfWeightedPixel = 0.0;\n"
"\n"
"float weight;\n"
"\n"
"weight = spline36_2_3(inputPos.y - (inputPosFloor.y - 2));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[0];\n"
"\n"
"weight = spline36_1_2(inputPos.y - (inputPosFloor.y - 1));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[1];\n"
"\n"
"weight = spline36_0_1(inputPos.y - (inputPosFloor.y + 0));\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[2];\n"
"\n"
"weight = spline36_0_1((inputPosFloor.y + 1) - inputPos.y);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[3];\n"
"\n"
"weight = spline36_1_2((inputPosFloor.y + 2) - inputPos.y);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[4];\n"
"\n"
"weight = spline36_2_3((inputPosFloor.y + 3) - inputPos.y);\n"
"sumOfWeights += weight;\n"
"sumOfWeightedPixel += weight * vertical[5];\n"
"\n"
"return float4((sumOfWeightedPixel / sumOfWeights).xyz, 1.0f);\n"
"}\n"
;
