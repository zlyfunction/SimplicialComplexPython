TEST_CASE("open_star_circle", "[simplicial_complex][star][2D]")
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
    std::vector<std::vector<long>> sc_v;
    t = m.tuple_from_id(PV, 2721);
    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 13);
    CHECK(sc_v[0][0] == 2721);
    CHECK(sc_v[1][0] == 2705);
    CHECK(sc_v[1][1] == 2721);
    CHECK(sc_v[2][0] == 2706);
    CHECK(sc_v[2][1] == 2721);
    CHECK(sc_v[3][0] == 2720);
    CHECK(sc_v[3][1] == 2721);
    CHECK(sc_v[4][0] == 2721);
    CHECK(sc_v[4][1] == 2722);
    CHECK(sc_v[5][0] == 2721);
    CHECK(sc_v[5][1] == 2736);
    CHECK(sc_v[6][0] == 2721);
    CHECK(sc_v[6][1] == 2737);
    CHECK(sc_v[7][0] == 2705);
    CHECK(sc_v[7][1] == 2706);
    CHECK(sc_v[7][2] == 2721);
    CHECK(sc_v[8][0] == 2705);
    CHECK(sc_v[8][1] == 2720);
    CHECK(sc_v[8][2] == 2721);
    CHECK(sc_v[9][0] == 2706);
    CHECK(sc_v[9][1] == 2721);
    CHECK(sc_v[9][2] == 2722);
    CHECK(sc_v[10][0] == 2720);
    CHECK(sc_v[10][1] == 2721);
    CHECK(sc_v[10][2] == 2736);
    CHECK(sc_v[11][0] == 2721);
    CHECK(sc_v[11][1] == 2722);
    CHECK(sc_v[11][2] == 2737);
    CHECK(sc_v[12][0] == 2721);
    CHECK(sc_v[12][1] == 2736);
    CHECK(sc_v[12][2] == 2737);

    t = m.tuple_from_id(PV, 4620);
    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 13);
    CHECK(sc_v[0][0] == 4620);
    CHECK(sc_v[1][0] == 4594);
    CHECK(sc_v[1][1] == 4620);
    CHECK(sc_v[2][0] == 4595);
    CHECK(sc_v[2][1] == 4620);
    CHECK(sc_v[3][0] == 4619);
    CHECK(sc_v[3][1] == 4620);
    CHECK(sc_v[4][0] == 4620);
    CHECK(sc_v[4][1] == 4621);
    CHECK(sc_v[5][0] == 4620);
    CHECK(sc_v[5][1] == 4646);
    CHECK(sc_v[6][0] == 4620);
    CHECK(sc_v[6][1] == 4647);
    CHECK(sc_v[7][0] == 4594);
    CHECK(sc_v[7][1] == 4595);
    CHECK(sc_v[7][2] == 4620);
    CHECK(sc_v[8][0] == 4594);
    CHECK(sc_v[8][1] == 4619);
    CHECK(sc_v[8][2] == 4620);
    CHECK(sc_v[9][0] == 4595);
    CHECK(sc_v[9][1] == 4620);
    CHECK(sc_v[9][2] == 4621);
    CHECK(sc_v[10][0] == 4619);
    CHECK(sc_v[10][1] == 4620);
    CHECK(sc_v[10][2] == 4646);
    CHECK(sc_v[11][0] == 4620);
    CHECK(sc_v[11][1] == 4621);
    CHECK(sc_v[11][2] == 4647);
    CHECK(sc_v[12][0] == 4620);
    CHECK(sc_v[12][1] == 4646);
    CHECK(sc_v[12][2] == 4647);

    t = m.tuple_from_id(PV, 4220);
    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 13);
    CHECK(sc_v[0][0] == 4220);
    CHECK(sc_v[1][0] == 4191);
    CHECK(sc_v[1][1] == 4220);
    CHECK(sc_v[2][0] == 4192);
    CHECK(sc_v[2][1] == 4220);
    CHECK(sc_v[3][0] == 4219);
    CHECK(sc_v[3][1] == 4220);
    CHECK(sc_v[4][0] == 4220);
    CHECK(sc_v[4][1] == 4221);
    CHECK(sc_v[5][0] == 4220);
    CHECK(sc_v[5][1] == 4249);
    CHECK(sc_v[6][0] == 4220);
    CHECK(sc_v[6][1] == 4250);
    CHECK(sc_v[7][0] == 4191);
    CHECK(sc_v[7][1] == 4192);
    CHECK(sc_v[7][2] == 4220);
    CHECK(sc_v[8][0] == 4191);
    CHECK(sc_v[8][1] == 4219);
    CHECK(sc_v[8][2] == 4220);
    CHECK(sc_v[9][0] == 4192);
    CHECK(sc_v[9][1] == 4220);
    CHECK(sc_v[9][2] == 4221);
    CHECK(sc_v[10][0] == 4219);
    CHECK(sc_v[10][1] == 4220);
    CHECK(sc_v[10][2] == 4249);
    CHECK(sc_v[11][0] == 4220);
    CHECK(sc_v[11][1] == 4221);
    CHECK(sc_v[11][2] == 4250);
    CHECK(sc_v[12][0] == 4220);
    CHECK(sc_v[12][1] == 4249);
    CHECK(sc_v[12][2] == 4250);

    t = m.tuple_from_id(PV, 3329);
    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 13);
    CHECK(sc_v[0][0] == 3329);
    CHECK(sc_v[1][0] == 177);
    CHECK(sc_v[1][1] == 3329);
    CHECK(sc_v[2][0] == 178);
    CHECK(sc_v[2][1] == 3329);
    CHECK(sc_v[3][0] == 3299);
    CHECK(sc_v[3][1] == 3329);
    CHECK(sc_v[4][0] == 3300);
    CHECK(sc_v[4][1] == 3329);
    CHECK(sc_v[5][0] == 3328);
    CHECK(sc_v[5][1] == 3329);
    CHECK(sc_v[6][0] == 3329);
    CHECK(sc_v[6][1] == 3330);
    CHECK(sc_v[7][0] == 177);
    CHECK(sc_v[7][1] == 178);
    CHECK(sc_v[7][2] == 3329);
    CHECK(sc_v[8][0] == 177);
    CHECK(sc_v[8][1] == 3329);
    CHECK(sc_v[8][2] == 3330);
    CHECK(sc_v[9][0] == 178);
    CHECK(sc_v[9][1] == 3328);
    CHECK(sc_v[9][2] == 3329);
    CHECK(sc_v[10][0] == 3299);
    CHECK(sc_v[10][1] == 3300);
    CHECK(sc_v[10][2] == 3329);
    CHECK(sc_v[11][0] == 3299);
    CHECK(sc_v[11][1] == 3328);
    CHECK(sc_v[11][2] == 3329);
    CHECK(sc_v[12][0] == 3300);
    CHECK(sc_v[12][1] == 3329);
    CHECK(sc_v[12][2] == 3330);

    t = m.tuple_from_id(PV, 2671);
    sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());
    REQUIRE(sc_v.size() == 13);
    CHECK(sc_v[0][0] == 2671);
    CHECK(sc_v[1][0] == 2655);
    CHECK(sc_v[1][1] == 2671);
    CHECK(sc_v[2][0] == 2656);
    CHECK(sc_v[2][1] == 2671);
    CHECK(sc_v[3][0] == 2670);
    CHECK(sc_v[3][1] == 2671);
    CHECK(sc_v[4][0] == 2671);
    CHECK(sc_v[4][1] == 2672);
    CHECK(sc_v[5][0] == 2671);
    CHECK(sc_v[5][1] == 2686);
    CHECK(sc_v[6][0] == 2671);
    CHECK(sc_v[6][1] == 2687);
    CHECK(sc_v[7][0] == 2655);
    CHECK(sc_v[7][1] == 2656);
    CHECK(sc_v[7][2] == 2671);
    CHECK(sc_v[8][0] == 2655);
    CHECK(sc_v[8][1] == 2670);
    CHECK(sc_v[8][2] == 2671);
    CHECK(sc_v[9][0] == 2656);
    CHECK(sc_v[9][1] == 2671);
    CHECK(sc_v[9][2] == 2672);
    CHECK(sc_v[10][0] == 2670);
    CHECK(sc_v[10][1] == 2671);
    CHECK(sc_v[10][2] == 2686);
    CHECK(sc_v[11][0] == 2671);
    CHECK(sc_v[11][1] == 2672);
    CHECK(sc_v[11][2] == 2687);
    CHECK(sc_v[12][0] == 2671);
    CHECK(sc_v[12][1] == 2686);
    CHECK(sc_v[12][2] == 2687);

}
