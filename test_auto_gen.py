from SimplicialComplex import *
import random

path = 'data/'
mesh_name = 'circle.obj'
output_file_name = 'test_code.cpp'
mesh = load_obj(path+mesh_name)
n_samples = 5
v_samples = random.sample(list(mesh.vertices), n_samples)

with open(output_file_name, 'w') as file:

    cpp_code = 'TEST_CASE("open_star_{mesh_name}", "[simplicial_complex][star][2D]")\n'.format(mesh_name=mesh_name.split(".")[0])+\
    '{\n'+\
    '    RowVectors3d V;\n'+\
    '    RowVectors3l F;\n'+\
    '    std::string name = "/{mesh_file}";\n'.format(mesh_file = mesh_name)+\
    '    std::string path;\n'+\
    '    path.append(WMTK_DATA_DIR);\n'+\
    '    path.append(name);\n'+\
    '    igl::read_triangle_mesh(path, V, F);\n'+\
    '    tests::DEBUG_TriMesh m;\n'+\
    '    m.initialize(F);\n'+\
    '\n'+\
    '    Tuple t;\n'+\
    '    std::vector<std::vector<long>> sc_v;\n'
    
    file.write(cpp_code)

    # print(v_samples)
    for v in v_samples:
        file.write("    t = m.tuple_from_id(PV, {});\n".format(v[0]))
        file.write("    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());\n")
        o_star = mesh.open_star(v)
        o_star = sorted(o_star, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_v.size() == {});\n".format(len(o_star)))
        for simplex in o_star:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_v[{}][{}] == {});\n".format(o_star.index(simplex), i, simplex[i]))
        file.write("\n")
    
    file.write("}\n")
