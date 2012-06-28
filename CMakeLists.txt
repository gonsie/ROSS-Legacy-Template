INCLUDE_DIRECTORIES(${ROSS_SOURCE_DIR})

SET(model_srcs
	model_driver.c  
	model.h
)

ADD_EXECUTABLE(ross-model model_main.c ${model_srcs})

TARGET_LINK_LIBRARIES(ross-model ROSS m)
