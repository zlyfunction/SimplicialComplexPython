TEST_CASE("link_circle", "[simplicial_complex][link][2D]")
{
    RowVectors3d V;
    RowVectors3l F;
    std::string name = "/circle.obj";
    std::string path;
    path.append(WMTK_DATA_DIR);
    path.append(name);
    igl::read_triangle_mesh(path, V, F);
    tests::DEBUG_TriMesh m;
    m.initialize(F);

    Tuple t;
    std::vector<std::vector<long>> sc_v, sc_e, sc_f;
    t = m.tuple_from_id(PV, 3342);
    sc_v = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 12);
    CHECK(sc_v[0][0] == 384);
    CHECK(sc_v[1][0] == 385);
    CHECK(sc_v[2][0] == 3341);
    CHECK(sc_v[3][0] == 3343);
    CHECK(sc_v[4][0] == 3344);
    CHECK(sc_v[5][0] == 3345);
    CHECK(sc_v[6][0] == 384);
    CHECK(sc_v[6][1] == 385);
    CHECK(sc_v[7][0] == 384);
    CHECK(sc_v[7][1] == 3341);
    CHECK(sc_v[8][0] == 385);
    CHECK(sc_v[8][1] == 3344);
    CHECK(sc_v[9][0] == 3341);
    CHECK(sc_v[9][1] == 3343);
    CHECK(sc_v[10][0] == 3343);
    CHECK(sc_v[10][1] == 3345);
    CHECK(sc_v[11][0] == 3344);
    CHECK(sc_v[11][1] == 3345);

    t = m.tuple_from_id(PV, 3467);
    sc_v = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 12);
    CHECK(sc_v[0][0] == 3451);
    CHECK(sc_v[1][0] == 3452);
    CHECK(sc_v[2][0] == 3466);
    CHECK(sc_v[3][0] == 3468);
    CHECK(sc_v[4][0] == 3483);
    CHECK(sc_v[5][0] == 3484);
    CHECK(sc_v[6][0] == 3451);
    CHECK(sc_v[6][1] == 3452);
    CHECK(sc_v[7][0] == 3451);
    CHECK(sc_v[7][1] == 3466);
    CHECK(sc_v[8][0] == 3452);
    CHECK(sc_v[8][1] == 3468);
    CHECK(sc_v[9][0] == 3466);
    CHECK(sc_v[9][1] == 3483);
    CHECK(sc_v[10][0] == 3468);
    CHECK(sc_v[10][1] == 3484);
    CHECK(sc_v[11][0] == 3483);
    CHECK(sc_v[11][1] == 3484);

    t = m.tuple_from_id(PV, 462);
    sc_v = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 12);
    CHECK(sc_v[0][0] == 461);
    CHECK(sc_v[1][0] == 463);
    CHECK(sc_v[2][0] == 4407);
    CHECK(sc_v[3][0] == 4424);
    CHECK(sc_v[4][0] == 4888);
    CHECK(sc_v[5][0] == 4906);
    CHECK(sc_v[6][0] == 461);
    CHECK(sc_v[6][1] == 4407);
    CHECK(sc_v[7][0] == 461);
    CHECK(sc_v[7][1] == 4888);
    CHECK(sc_v[8][0] == 463);
    CHECK(sc_v[8][1] == 4424);
    CHECK(sc_v[9][0] == 463);
    CHECK(sc_v[9][1] == 4906);
    CHECK(sc_v[10][0] == 4407);
    CHECK(sc_v[10][1] == 4424);
    CHECK(sc_v[11][0] == 4888);
    CHECK(sc_v[11][1] == 4906);

    t = m.tuple_from_id(PV, 2714);
    sc_v = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 12);
    CHECK(sc_v[0][0] == 2698);
    CHECK(sc_v[1][0] == 2699);
    CHECK(sc_v[2][0] == 2713);
    CHECK(sc_v[3][0] == 2715);
    CHECK(sc_v[4][0] == 2729);
    CHECK(sc_v[5][0] == 2730);
    CHECK(sc_v[6][0] == 2698);
    CHECK(sc_v[6][1] == 2699);
    CHECK(sc_v[7][0] == 2698);
    CHECK(sc_v[7][1] == 2713);
    CHECK(sc_v[8][0] == 2699);
    CHECK(sc_v[8][1] == 2715);
    CHECK(sc_v[9][0] == 2713);
    CHECK(sc_v[9][1] == 2729);
    CHECK(sc_v[10][0] == 2715);
    CHECK(sc_v[10][1] == 2730);
    CHECK(sc_v[11][0] == 2729);
    CHECK(sc_v[11][1] == 2730);

    t = m.tuple_from_id(PV, 835);
    sc_v = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 7);
    CHECK(sc_v[0][0] == 86);
    CHECK(sc_v[1][0] == 87);
    CHECK(sc_v[2][0] == 820);
    CHECK(sc_v[3][0] == 834);
    CHECK(sc_v[4][0] == 86);
    CHECK(sc_v[4][1] == 87);
    CHECK(sc_v[5][0] == 87);
    CHECK(sc_v[5][1] == 820);
    CHECK(sc_v[6][0] == 820);
    CHECK(sc_v[6][1] == 834);

    t = m.edge_tuple_from_vids(207,3796);
    sc_e = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PE, t)).get_simplex_vector());
    REQUIRE(sc_e.size() == 2);
    CHECK(sc_e[0][0] == 206);
    CHECK(sc_e[1][0] == 3795);

    t = m.edge_tuple_from_vids(1516,1530);
    sc_e = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PE, t)).get_simplex_vector());
    REQUIRE(sc_e.size() == 2);
    CHECK(sc_e[0][0] == 1517);
    CHECK(sc_e[1][0] == 1529);

    t = m.edge_tuple_from_vids(3508,3509);
    sc_e = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PE, t)).get_simplex_vector());
    REQUIRE(sc_e.size() == 2);
    CHECK(sc_e[0][0] == 3491);
    CHECK(sc_e[1][0] == 3527);

    t = m.edge_tuple_from_vids(4182,4209);
    sc_e = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PE, t)).get_simplex_vector());
    REQUIRE(sc_e.size() == 2);
    CHECK(sc_e[0][0] == 4181);
    CHECK(sc_e[1][0] == 4210);

    t = m.edge_tuple_from_vids(112,113);
    sc_e = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PE, t)).get_simplex_vector());
    REQUIRE(sc_e.size() == 2);
    CHECK(sc_e[0][0] == 891);
    CHECK(sc_e[1][0] == 2505);

    t = m.face_tuple_from_vids(3560, 3561, 3582);
    sc_f = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PF, t)).get_simplex_vector());
    REQUIRE(sc_f.size() == 0);

    t = m.face_tuple_from_vids(2351, 2352, 2367);
    sc_f = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PF, t)).get_simplex_vector());
    REQUIRE(sc_f.size() == 0);

    t = m.face_tuple_from_vids(1231, 1232, 1247);
    sc_f = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PF, t)).get_simplex_vector());
    REQUIRE(sc_f.size() == 0);

    t = m.face_tuple_from_vids(3863, 3864, 3875);
    sc_f = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PF, t)).get_simplex_vector());
    REQUIRE(sc_f.size() == 0);

    t = m.face_tuple_from_vids(653, 654, 665);
    sc_f = get_sorted_sc(m, SimplicialComplex::link(m, Simplex(PF, t)).get_simplex_vector());
    REQUIRE(sc_f.size() == 0);

}
